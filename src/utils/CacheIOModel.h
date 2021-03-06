#ifndef CACHEIOMODEL_H_INCLUDED
#define CACHEIOMODEL_H_INCLUDED

#include<cstring>
#include<string>
#include<cstdlib>
#include<unistd.h>
#include<cstdio>

int readInt(const char* cache);

void writeInt(char* cache, int n);

void writeFloat(char* cache, float f);

float readFloat(const char* cache);

std::string readString(const char* cache, int len);

void writeString(char* cache, std::string& str, int len);

bool readBool(const char* cache);

void writeBool(char* cache, bool b);

void copyData(const char* src, char* dest, int len);

void write_id(char* cache);

std::string read_id(const char* cache);

#endif // CACHEIOMODEL_H_INCLUDED
