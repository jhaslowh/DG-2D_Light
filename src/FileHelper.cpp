#include "FileHelper.h"

// Load a texture into opengl 
int loadPNG(std::string file){
    // Generate opengl textures
    GLuint textureHandle;
    glGenTextures(1, &textureHandle);

    // Load texture with soil 
    int width, height;
    unsigned char* image =
        SOIL_load_image(file.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    
    // Set the active texture unit to texture unit 0.
    // Other units are used for different things. 0 is default, so 
    // we use that for general actions. 
    glActiveTexture(GL_TEXTURE0);
    // Bind to the texture in OpenGL
    glBindTexture(GL_TEXTURE_2D, textureHandle);
    // Load texture into bound texture 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
              GL_UNSIGNED_BYTE, image);
                 
    // Set filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Free image data
    SOIL_free_image_data(image);

    // Unload texture
    glBindTexture(GL_TEXTURE_2D, 0);

    return textureHandle;
}

// ---------------------------------------- //
//       Helper Methods                     //
// ---------------------------------------- // 

// Convert int to string
std::string toString(int value){
    std::ostringstream buff;
    buff<<value;
    return buff.str();   
}

// Convert double to string
std::string toString(double value){
    std::ostringstream buff;
    buff<<value;
    return buff.str();   
}

// Convert string to int
int toInt(std::string s){
    int numb;
    std::istringstream (s) >> numb;
    return numb;
}

// Convert string to double
double toDouble(std::string s){
    double numb;
    std::istringstream (s) >> numb;
    return numb;
}

// Check if a file exists
bool fexists(const char *filename)
{
  std::ifstream ifile(filename);
  return ifile.is_open();
}
