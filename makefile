CC = g++
CXXFLAGS  = -g -std=c++0x -Wall

MKDIR_P = mkdir -p
OUT_DIR = build_dir

.PHONY: directories

all: directories strats

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}

strats: main.cpp ${OUT_DIR}/err_codes.o ${OUT_DIR}/Strat3.o ${OUT_DIR}/Strat2.o ${OUT_DIR}/Strat1.o ${OUT_DIR}/Logger.o ${OUT_DIR}/ValueGenerator.o ${OUT_DIR}/StrategyTester.o ${OUT_DIR}/FileHandler.o ${OUT_DIR}/ArgParser.o
	$(CC) $(CXXFLAGS) -o strats main.cpp ${OUT_DIR}/err_codes.o ${OUT_DIR}/Strat3.o ${OUT_DIR}/Strat2.o ${OUT_DIR}/Strat1.o ${OUT_DIR}/Logger.o ${OUT_DIR}/ValueGenerator.o ${OUT_DIR}/StrategyTester.o ${OUT_DIR}/FileHandler.o ${OUT_DIR}/ArgParser.o

${OUT_DIR}/Strat3.o: src/strat_3/Strat3.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/Strat3.o -c src/strat_3/Strat3.cpp

${OUT_DIR}/Strat2.o: src/strat_2/Strat2.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/Strat2.o -c src/strat_2/Strat2.cpp

${OUT_DIR}/Strat1.o: src/strat_1/Strat1.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/Strat1.o -c src/strat_1/Strat1.cpp

${OUT_DIR}/Logger.o: src/Logger.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/Logger.o -c src/Logger.cpp

${OUT_DIR}/ValueGenerator.o: src/ValueGenerator.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/ValueGenerator.o -c src/ValueGenerator.cpp

${OUT_DIR}/StrategyTester.o: src/StrategyTester.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/StrategyTester.o -c src/StrategyTester.cpp

${OUT_DIR}/FileHandler.o: src/FileHandler.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/FileHandler.o -c src/FileHandler.cpp

${OUT_DIR}/ArgParser.o: src/ArgParser.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/ArgParser.o -c src/ArgParser.cpp

${OUT_DIR}/err_codes.o: src/err_codes.cpp
	$(CC) $(CXXFLAGS) -o ${OUT_DIR}/err_codes.o -c src/err_codes.cpp

clean:
	rm -rf ${OUT_DIR}/ strats *.dSYM
