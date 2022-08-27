#ifndef _IMAGE_H
#define _IMAGE_H
#include <filesystem>
#include <iostream>
class Image {


    int width;
    int height;
    int nrChannels;



    // Image(const Image& other);
    // Image& operator=(const Image& other) = delete;


public:
    Image(std::filesystem::path path);
    ~Image();
    bool hasData();
    int getWidth();
    int getHeight();
    int getNrChannels();
    unsigned char *data;
};
#endif

