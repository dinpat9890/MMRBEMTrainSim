from org.apache.subversion.javahl import SVNClient, CommitInfo, ClientException
from org.apache.subversion.javahl.types import Revision, Depth, NodeKind, Status, CopySource
from java.util import Set, HashSet, Vector
from urlparse import urljoin

client       = SVNClient()
return_value = 0

class Results:
  pass
results = Results()

# Function that takes the path on disk and returns the revision that the head of the path is at
def get_root_revision(path):
  # http://subversion.apache.org/docs/javahl/1.8/org/tigris/subversion/javahl/Info2.html
  def cb(info):
    results.rev = info.rev

  try:
    client.info2(path, Revision.WORKING, Revision.HEAD, Depth.empty, None, cb)
  except ClientException, e:
    print e.getMessage()
    return ""
    
  return str(results.rev)
  
# Function that takes the path on disk and returns the revision of the last change in that path
def get_path_revision(path):
  # http://subversion.apache.org/docs/javahl/1.8/org/tigris/subversion/javahl/Info2.html
  def cb(info):
    results.rev = info.lastChangedRev

  try:
    client.info2(path, Revision.WORKING, Revision.HEAD, Depth.empty, None, cb)
  except ClientException, e:
    print e.getMessage()
    return ""
    
  return str(results.rev)
  
# Function that takes a URL and determines whether it exists or not
def exists(url):
  
  # This callback needs to be defined but is a no-op
  def cb(info):
    pass
    
  try:
    client.info2(url, Revision.HEAD, Revision.HEAD, Depth.empty, None, cb)
  except ClientException, e:
    print e.getMessage()
    return 0
    
  return 1

# Function that takes the path on disk and returns SVN url associated with the path  
def get_url(path):
  # http://subversion.apache.org/docs/javahl/1.8/org/tigris/subversion/javahl/Info2.html
  def cb(info):
    results.url = info.url

  try:
    client.info2(path, Revision.HEAD, Revision.HEAD, Depth.empty, None, cb)
  except ClientException, e:
    print e.getMessage()
    return ""
    
  return str(results.url)

# Function that takes the path on disk and returns SVN repo root url associated with the path  
def get_repo_root_url(path):
  # http://subversion.apache.org/docs/javahl/1.8/org/tigris/subversion/javahl/Info2.html
  def cb(info):
    results.url = info.reposRootUrl

  try:
    client.info2(path, Revision.HEAD, Revision.HEAD, Depth.empty, None, cb)
  except ClientException, e:
    print e.getMessage()
    return ""
    
  return str(results.url)
  
# Function that takes the path on disk and commits with the given commit message    
def commit(path,message):
  
  # Defines the commit message callback which must return our commit message
  def commit_message_cb(elements):
    return message
  
  try:
    files = HashSet()
    files.add(path)
    client.commit(files, Depth.infinity, True, True, None, None, commit_message_cb, None)
  except ClientException, e:
    print e.getMessage()
    return -1
    
    return 0
  
# Function that takes the path on disk, adds unversioned files, deletes missing files
# and commits with the given commit message    
def add_delete_commit(path,message):
  
  # Defines the status callback which will process each interesting file - add the
  # unversioned and delete the missing files
  def status_cb(path, status):
      prop_status = status.getTextStatus()
      if prop_status == Status.Kind.unversioned:
        client.add(path, Depth.infinity, True, True, True, True)
      elif prop_status == Status.Kind.missing:
        p = HashSet()
        p.add(path)
        client.remove(p, True, False, None, None, None)  
  
  # Defines the commit message callback which must return our commit message
  def commit_message_cb(elements):
    return message
  
  try:
    client.status(path, Depth.infinity, True, False, True, True, None, status_cb)
    files = HashSet()
    files.add(path)
    client.commit(files, Depth.infinity, True, True, None, None, commit_message_cb, None)
  except ClientException, e:
    print e.getMessage()
    return -1
    
    return 0
    
# Function that copies from the "from_url" to the "to_url" and commits the change using
# the commit message. Server side operation.  
def copy_url(from_url,to_url,message):
  def commit_message_cb(elements):
    return message
   
  try:   
    copy_source = CopySource(from_url, Revision.HEAD, None)
    sources     = Vector()
    sources.add(copy_source)
    client.copy(sources, to_url, False, True, False, None, commit_message_cb, None)
  except ClientException, e:
    print e.getMessage()
    return -1
    
    return 0
    
# Function that checks for modifications on the given path, returning 1 if there
# are changes and 0 if there aren't
def check_modified(path):
  
  # As soon as we receive a status callback we know that there are modified files on the given path
  def status_cb(path, status):
  
    # This is really not nice and is fixed in Python 3.0 with the use of the non_local keyword
    # There is no other way of getting this information back out to the next level of scope
    if not status.isIgnored():
      if (not status.isManaged()) or status.isModified():
        print "Modified: " + path
        global return_value
        return_value = 1
  
  try:
  
    # This is really not nice and is fixed in Python 3.0 with the use of the non_local keyword
    global return_value
    return_value = 0
    client.status(path, Depth.infinity, True, False, True, True, None, status_cb)
    return return_value
  except ClientException, e:
    print e.getMessage()
    return -1    
    
# Performs an SVN update on the given path  
def update(path):

  try:
    paths = HashSet()
    paths.add(path)
    client.update(paths, Revision.HEAD, Depth.infinity, False, False, False, False)
  except ClientException, e:
    print e.getMessage()
    return -1
    
    return 0
    
# Performs an SVN checkout from the given URL to the given path on disk  
def checkout(url,path,recurse):

  try:
    client.checkout(url, path, Revision.HEAD, Revision.HEAD, Depth.infinityOrImmediates(recurse), False, False)
  except ClientException, e:
    print e.getMessage()
    return -1
    
  return 0
  
# Performs an SVN export from the given URL to the given path on disk  
def export(url,path):

  try:
    client.doExport(url, path, Revision.HEAD, Revision.HEAD, True, True, Depth.infinity, None)
  except ClientException, e:
    print e.getMessage()
    return -1
    
  return 0
  
# Performs a mkdir on the server, commiting to the repository with the given message
def mkdir(url,message):
  def mkdir_message_cb(elements):
    return message
  
  try:  
    paths = HashSet()
    paths.add(url)
    client.mkdir(paths, True, None, mkdir_message_cb, None)
  except ClientException, e:
    print e.getMessage()
    return -1
  
  return 0
  
# Function that switches the working copy at the path provided to the URL specified 
def switch(path,url): 
  try:   
    client.doSwitch(path, url, Revision.HEAD, Revision.HEAD, Depth.infinity, False, True, False, False)
  except ClientException, e:
    print e.getMessage()
    return -1
    
    return 0