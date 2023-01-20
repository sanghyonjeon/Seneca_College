#ifndef NAMESPACE_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define NAMESPACE_FILE_H

bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);

#endif