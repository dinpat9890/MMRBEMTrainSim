@echo off
set ARCH=x86
if [%1]==[Win32] set ARCH=x86
if [%1]==[x64]   set ARCH=x64

set PATH=%~dp0..\COTS\vc_redist\%ARCH%\crt;%PATH%