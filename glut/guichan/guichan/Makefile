CPP := g++
AR := ar cru
RANLIB := ranlib 
RM := rm -rf

CPPFLAGS := 
CPPFLAGS += -DHAVE_CONFIG_H 
CPPFLAGS += -I.   
CPPFLAGS += -g -O2 -Wall -Wno-unused 
CPPFLAGS += -DGUICHAN_BUILD

CPPFLAGS += -I/local/include

EXAMPLES_CPPFLAGS := -Werror -Wall -Wno-unused 
EXAMPLES_CPPFLAGS += -I/local/include -L/local/lib -L.
EXAMPLES_CPPFLAGS += -lguichan -lSDL_image -lmingw32 -lSDLmain -lSDL -lglaux -lglu32 -lopengl32 -lwinmm -lgdi32

OBJS := 
OBJS += actionevent.o basiccontainer.o cliprectangle.o 
OBJS += color.o defaultfont.o event.o exception.o 
OBJS += focushandler.o font.o genericinput.o 
OBJS += graphics.o gui.o guichan.o image.o 
OBJS += imagefont.o inputevent.o key.o 
OBJS += keyevent.o keyinput.o mouseevent.o 
OBJS += mouseinput.o rectangle.o selectionevent.o widget.o

OBJS += widgets/button.o widgets/checkbox.o widgets/container.o widgets/dropdown.o 
OBJS += widgets/icon.o widgets/imagebutton.o widgets/label.o widgets/listbox.o 
OBJS += widgets/radiobutton.o widgets/scrollarea.o widgets/slider.o 
OBJS += widgets/tab.o widgets/tabbedarea.o widgets/textbox.o 
OBJS += widgets/textfield.o widgets/window.o

OBJS += opengl/opengl.o opengl/openglgraphics.o opengl/openglimage.o

OBJS += opengl/opengl.o opengl/openglgraphics.o opengl/openglimage.o

OBJS += sdl/sdl.o sdl/sdlgraphics.o sdl/sdlimage.o
OBJS += sdl/sdlimageloader.o sdl/sdlinput.o

BIMS := openglsdlhelloworld.exe openglsdlwidgets.exe openglsdlaction.exe 
BIMS += sdlhelloworld.exe sdlwidgets.exe sdlaction.exe

all : libguichan.a $(BIMS)

libguichan.a : $(OBJS)
	$(AR) $@ $(OBJS)
	$(RANLIB) $@

openglsdlhelloworld.exe:
	$(CPP) examples/openglsdlhelloworld.cpp -o openglsdlhelloworld.exe $(EXAMPLES_CPPFLAGS)
	
openglsdlwidgets.exe:	
	$(CPP) examples/openglsdlwidgets.cpp -o openglsdlwidgets.exe $(EXAMPLES_CPPFLAGS)

openglsdlaction.exe:
	$(CPP) examples/openglsdlaction.cpp -o openglsdlaction.exe $(EXAMPLES_CPPFLAGS)
	
sdlhelloworld.exe:
	$(CPP) examples/sdlhelloworld.cpp -o sdlhelloworld.exe $(EXAMPLES_CPPFLAGS)
	
sdlwidgets.exe:	
	$(CPP) examples/sdlwidgets.cpp -o sdlwidgets.exe $(EXAMPLES_CPPFLAGS)
	
sdlaction.exe:
	$(CPP) examples/sdlaction.cpp -o sdlaction.exe $(EXAMPLES_CPPFLAGS)
	
%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<
	
clean :
	$(RM) $(OBJS) libguichan.a $(BIMS)
