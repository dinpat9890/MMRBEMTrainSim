@echo off
set ARCH=Win32
if [%1]==[Win32] set ARCH=Win32
if [%1]==[x64]   set ARCH=x64

set PATH=%~dp0..\COTS\xerces\Bin\%ARCH%;%PATH%