CXX = g++
CXXSTANDARD = -std=c++17
OPTFLAGS = -O3 -flto -fwhole-program -funroll-loops
MFLAGS = -march=native -mtune=native
WFLAGS = -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wformat-security -Winline -Wformat=2 \
-Wattributes -Wbuiltin-macro-redefined -Wcast-align -Wdiv-by-zero -Wdouble-promotion -Wfloat-equal \
-Wint-to-pointer-cast -Wlogical-op -Woverflow -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo \
-Wwrite-strings -Wimplicit-fallthrough=5 -Wstringop-overflow=4 -Wstrict-aliasing=3
CXXFLAGS = $(CXXSTANDARD) $(OPTFLAGS) $(MFLAGS) $(PFLAGS) $(WFLAGS)
SRC = lidDrivenCavity.C omegaPsiFormulation.C runTimeControl.C IOControl.C scalarArrays.C meshTools.C

default:
	$(CXX) $(CXXFLAGS) -o lidDrivenCavity $(SRC)

clean:
	rm lidDrivenCavity