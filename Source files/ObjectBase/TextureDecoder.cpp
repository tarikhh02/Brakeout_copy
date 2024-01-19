#define STB_IMAGE_IMPLEMENTATION

#include "ObjectBase.h"
#include "stb_image.h"

bool ObjectBase::DecodeTexture()
{
	if (width == 0 || height == 0)
		return false;

	if (imageDecoded)
		free(imageDecoded);

	imageDecoded = (unsigned int*)malloc(width * height * sizeof(unsigned int));

	int imgWidth, imgHeight, channels;
	unsigned char* image = stbi_load(texturePath, &imgWidth, &imgHeight, &channels, 0);

	if (!image)
		return false;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			float adaptationWidthValue = (float)x / (float)width * (float)imgWidth;
			float adaptationHeightValue = (float)y / (float)height * (float)imgHeight;

			int topPixelsIndex = (int)adaptationHeightValue * imgWidth + (int)adaptationWidthValue;
			int bottomPixelsIndex = ((int)adaptationHeightValue + 1) * imgWidth + (int)adaptationWidthValue;

			unsigned char* rgbColors = new unsigned char[channels];
			for (int channel = 0; channel < channels; channel++)
			{
				//Using bilinear interpolation to shrink image to the size I need
				rgbColors[channel] = ObjectBase::PerformBilinearInterpolation(ObjectBase::PerformBilinearInterpolation(image[topPixelsIndex * channels + channel], image[(topPixelsIndex + 1) * channels + channel], (adaptationWidthValue - (int)adaptationWidthValue))
																			, ObjectBase::PerformBilinearInterpolation(image[bottomPixelsIndex * channels + channel], image[(bottomPixelsIndex + 1) * channels + channel], (adaptationWidthValue - (int)adaptationWidthValue))
																			, (adaptationHeightValue - (int)adaptationHeightValue));
			}

			unsigned int color = (*(rgbColors) << 16) | (*(rgbColors + 1) << 8) | (*(rgbColors + 2));

			imageDecoded[y * width + x] = color;

			delete[] rgbColors;
		}
	}

	stbi_image_free(image);

	return true;
}

float ObjectBase::PerformBilinearInterpolation(float lowerValue, float higherValue, float ratio)
{
	//bilinear interpolation --> a + t * (b - a)
	return lowerValue + ratio * (higherValue - lowerValue);
}