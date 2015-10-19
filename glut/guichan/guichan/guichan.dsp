# Microsoft Developer Studio Project File - Name="guichan" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=guichan - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "guichan.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "guichan.mak" CFG="guichan - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "guichan - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "guichan - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "guichan - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /I "../SDL/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "guichan - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "../SDL/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "guichan - Win32 Release"
# Name "guichan - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "widgets"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\widgets\adjustingcontainer.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\adjustingcontainer.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\button.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\button.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\checkbox.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\checkbox.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\container.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\container.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\dropdown.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\dropdown.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\icon.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\icon.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\imagebutton.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\imagebutton.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\label.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\label.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\listbox.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\listbox.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\radiobutton.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\radiobutton.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\scrollarea.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\scrollarea.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\slider.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\slider.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\tab.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\tab.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\tabbedarea.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\tabbedarea.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\textbox.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\textbox.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\textfield.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\textfield.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets\window.cpp
# End Source File
# Begin Source File

SOURCE=.\widgets\window.hpp
# End Source File
# End Group
# Begin Group "sdl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sdl\sdl.cpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlgraphics.cpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlgraphics.hpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlimage.cpp

!IF  "$(CFG)" == "guichan - Win32 Release"

!ELSEIF  "$(CFG)" == "guichan - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sdl\sdlimage.hpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlimageloader.cpp

!IF  "$(CFG)" == "guichan - Win32 Release"

!ELSEIF  "$(CFG)" == "guichan - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sdl\sdlimageloader.hpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlinput.cpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlinput.hpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdlpixel.hpp
# End Source File
# Begin Source File

SOURCE=.\sdl\sdltruetypefont.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\sdl\sdltruetypefont.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\actionevent.cpp
# End Source File
# Begin Source File

SOURCE=.\actionevent.hpp
# End Source File
# Begin Source File

SOURCE=.\actionlistener.hpp
# End Source File
# Begin Source File

SOURCE=.\basiccontainer.cpp
# End Source File
# Begin Source File

SOURCE=.\basiccontainer.hpp
# End Source File
# Begin Source File

SOURCE=.\cliprectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\cliprectangle.hpp
# End Source File
# Begin Source File

SOURCE=.\color.cpp
# End Source File
# Begin Source File

SOURCE=.\color.hpp
# End Source File
# Begin Source File

SOURCE=.\deathlistener.hpp
# End Source File
# Begin Source File

SOURCE=.\defaultfont.cpp
# End Source File
# Begin Source File

SOURCE=.\defaultfont.hpp
# End Source File
# Begin Source File

SOURCE=.\event.cpp
# End Source File
# Begin Source File

SOURCE=.\event.hpp
# End Source File
# Begin Source File

SOURCE=.\exception.cpp
# End Source File
# Begin Source File

SOURCE=.\exception.hpp
# End Source File
# Begin Source File

SOURCE=.\focushandler.cpp
# End Source File
# Begin Source File

SOURCE=.\focushandler.hpp
# End Source File
# Begin Source File

SOURCE=.\focuslistener.hpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\font.hpp
# End Source File
# Begin Source File

SOURCE=.\genericinput.cpp
# End Source File
# Begin Source File

SOURCE=.\genericinput.hpp
# End Source File
# Begin Source File

SOURCE=.\graphics.cpp
# End Source File
# Begin Source File

SOURCE=.\graphics.hpp
# End Source File
# Begin Source File

SOURCE=.\gui.cpp
# End Source File
# Begin Source File

SOURCE=.\gui.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan.hpp
# End Source File
# Begin Source File

SOURCE=.\image.cpp
# End Source File
# Begin Source File

SOURCE=.\image.hpp
# End Source File
# Begin Source File

SOURCE=.\imagefont.cpp
# End Source File
# Begin Source File

SOURCE=.\imagefont.hpp
# End Source File
# Begin Source File

SOURCE=.\imageloader.hpp
# End Source File
# Begin Source File

SOURCE=.\input.hpp
# End Source File
# Begin Source File

SOURCE=.\inputevent.cpp
# End Source File
# Begin Source File

SOURCE=.\inputevent.hpp
# End Source File
# Begin Source File

SOURCE=.\key.cpp
# End Source File
# Begin Source File

SOURCE=.\key.hpp
# End Source File
# Begin Source File

SOURCE=.\keyevent.cpp
# End Source File
# Begin Source File

SOURCE=.\keyevent.hpp
# End Source File
# Begin Source File

SOURCE=.\keyinput.cpp
# End Source File
# Begin Source File

SOURCE=.\keyinput.hpp
# End Source File
# Begin Source File

SOURCE=.\keylistener.hpp
# End Source File
# Begin Source File

SOURCE=.\listmodel.hpp
# End Source File
# Begin Source File

SOURCE=.\mouseevent.cpp
# End Source File
# Begin Source File

SOURCE=.\mouseevent.hpp
# End Source File
# Begin Source File

SOURCE=.\mouseinput.cpp
# End Source File
# Begin Source File

SOURCE=.\mouseinput.hpp
# End Source File
# Begin Source File

SOURCE=.\mouselistener.hpp
# End Source File
# Begin Source File

SOURCE=.\opengl.hpp
# End Source File
# Begin Source File

SOURCE=.\platform.hpp
# End Source File
# Begin Source File

SOURCE=.\rectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\rectangle.hpp
# End Source File
# Begin Source File

SOURCE=.\sdl.hpp
# End Source File
# Begin Source File

SOURCE=.\selectionevent.cpp
# End Source File
# Begin Source File

SOURCE=.\selectionevent.hpp
# End Source File
# Begin Source File

SOURCE=.\selectionlistener.hpp
# End Source File
# Begin Source File

SOURCE=.\widget.cpp
# End Source File
# Begin Source File

SOURCE=.\widget.hpp
# End Source File
# Begin Source File

SOURCE=.\widgetlistener.hpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
