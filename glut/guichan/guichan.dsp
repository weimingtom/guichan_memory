# Microsoft Developer Studio Project File - Name="guichan" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

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
!MESSAGE "guichan - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "guichan - Win32 Debug" (based on "Win32 (x86) Console Application")
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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /I "." /I "./include" /I "./sdlmod" /I "./loader" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_CRT_SECURE_NO_WARNINGS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib pthreadVC2.lib ws2_32.lib /nologo /subsystem:console /machine:I386 /libpath:"./lib"

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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "." /I "./include" /I "./sdlmod" /I "./loader" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_CRT_SECURE_NO_WARNINGS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib pthreadVC2.lib ws2_32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"./lib"

!ENDIF 

# Begin Target

# Name "guichan - Win32 Release"
# Name "guichan - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "guichan"

# PROP Default_Filter ""
# Begin Group "guichan_widgets"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\guichan\widgets\adjustingcontainer.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\adjustingcontainer.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\button.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\button.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\checkbox.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\checkbox.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\container.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\container.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\dropdown.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\dropdown.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\icon.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\icon.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\imagebutton.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\imagebutton.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\label.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\label.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\listbox.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\listbox.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\radiobutton.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\radiobutton.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\scrollarea.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\scrollarea.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\slider.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\slider.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\tab.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\tab.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\tabbedarea.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\tabbedarea.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\textbox.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\textbox.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\textfield.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\textfield.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\window.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgets\window.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\guichan\actionevent.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\actionevent.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\actionlistener.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\basiccontainer.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\basiccontainer.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\cliprectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\cliprectangle.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\color.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\color.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\deathlistener.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\defaultfont.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\defaultfont.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\event.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\event.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\exception.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\exception.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\focushandler.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\focushandler.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\focuslistener.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\font.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\font.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\genericinput.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\genericinput.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\graphics.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\graphics.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\gui.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\gui.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\guichan.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\guichan.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\image.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\image.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\imagefont.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\imagefont.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\imageloader.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\input.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\inputevent.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\inputevent.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\key.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\key.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\keyevent.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\keyevent.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\keyinput.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\keyinput.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\keylistener.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\listmodel.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\mouseevent.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\mouseevent.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\mouseinput.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\mouseinput.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\mouselistener.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\opengl.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\platform.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\rectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\rectangle.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\sdl.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\selectionevent.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\selectionevent.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\selectionlistener.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widget.cpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widget.hpp
# End Source File
# Begin Source File

SOURCE=.\guichan\widgetlistener.hpp
# End Source File
# End Group
# Begin Group "sdlmod"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_audio.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_audio.h
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_blit_0.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_blit_1.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_blit_A.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_blit_N.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_endian.h
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_events.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_events.h
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_ext_pixel.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_ext_pixel.h
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_surface.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_timer.c
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_timer.h
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_video.h
# End Source File
# Begin Source File

SOURCE=.\sdlmod\SDLMOD_yuv.c
# End Source File
# End Group
# Begin Group "test"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\test\opengl_sample.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\test\test001.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "loader"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\loader\TextureLoader.c
# End Source File
# Begin Source File

SOURCE=.\loader\TextureLoader.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\glutgraphics.cpp
# End Source File
# Begin Source File

SOURCE=.\glutimage.cpp
# End Source File
# Begin Source File

SOURCE=.\glutimageloader.cpp
# End Source File
# Begin Source File

SOURCE=.\glutinput.cpp
# End Source File
# Begin Source File

SOURCE=.\glutwidgets.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\glut.hpp
# End Source File
# Begin Source File

SOURCE=.\glutgraphics.hpp
# End Source File
# Begin Source File

SOURCE=.\glutimage.hpp
# End Source File
# Begin Source File

SOURCE=.\glutimageloader.hpp
# End Source File
# Begin Source File

SOURCE=.\glutinput.hpp
# End Source File
# Begin Source File

SOURCE=.\widgets.hpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
