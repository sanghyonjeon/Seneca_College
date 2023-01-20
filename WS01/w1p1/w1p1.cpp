#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;



bool loadMovies();
bool hasGenre(const Movie* mvp, const char genre[]);
void displayMovie(const Movie* mvp);
void displayMoviesWithGenre(const char genre[]);
bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);
void flushkeys();
bool yes();