BUILD_DIR = build
OBJ_DIR := $(BUILD_DIR)/objs

LIB_DIR := $(BUILD_DIR)/libs
DLIBDIR := $(LIB_DIR)/dynamic
SLIBDIR := $(LIB_DIR)/static
LLIBDIR := $(LIB_DIR)/sdo


ifeq ($(OS),Windows_NT)
SLIB := $(SLIBDIR)/Lexi-s.obj
DLIB := $(DLIBDIR)/Lexi-d.dll
else
SLIB := $(SLIBDIR)/Lexi-s.a
DLIB := $(DLIBDIR)/Lexi-d.so
endif

LEXI_DIR = Lexi
MATA_DIR = Mata

PSRC := $(wildcard $(LEXI_DIR)/*.cpp) $(wildcard $(MATA_DIR)/*.cpp)
POBJ := $(patsubst %.cpp, $(LLIBDIR)/%.obj, $(PSRC))

CXX = g++
AR = ar
ARFLAGS = rcs
CXXFLAGSL = -fpic

LDFLAGSL = -shared

MKDIR = python mkdir.py


PHONYT = all static dynamic
all: static dynamic # tests

PHONYT += dynlink
dynamic: $(POBJ) dynlink

PHONYT += statlink
static: $(POBJ) statlink


$(LLIBDIR)/%.obj: ./%.cpp
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGSL) -c $(call FixPath,$^) -o $(call FixPath,$@)

dynlink:
	$(MKDIR) $(dir $(DLIB))
	$(CXX) $(LDFLAGSL) $(POBJ) -o $(DLIB)

statlink:
	$(MKDIR) $(dir $(SLIB))
	$(AR) $(ARFLAGS) $(SLIB) $(POBJ)

.PHONY : $(PHONYT)