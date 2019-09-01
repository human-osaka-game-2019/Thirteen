#ifndef MAP_CHIP_DATA_H
#define MAP_CHIP_DATA_H

class MapChipData
{
public:
	const int Map_HeightNumber = 10;
	const int Map_WidthNumber = 10;

	// マップチップの大きさ
	void SetMapChipSize(float Height, float Width);

	void SetTextureSize(float Height, float Width);

	float x;
	float y;
	float chip_x;
	float chip_y;

private:
	float Texture_Height;
	float Texture_Width;

	float MapChipHeight;
	float MapChipWidth;
};

#endif // !MAP_CHIP_DATA
