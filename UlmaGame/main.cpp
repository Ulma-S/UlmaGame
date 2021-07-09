#include "ApplicationCore.h"
#include "WindowOpenGL.h"
#include "InputManagerOpenGL.h"
#include "ShaderLoaderOpenGL.h"
#include "ServiceLocator.h"

#include <ft2build.h>
#include FT_FREETYPE_H

using namespace UlmaEngine;

int main() {

	//FT_Library library;
	//FT_Face face;
	//FT_GlyphSlot slot;

	//FT_Init_FreeType(&library);
	//FT_New_Face(library, R"(C:\Windows\Fonts\Meiryo.ttc)", 0, &face);
	//FT_Set_Pixel_Sizes(face, 0, 48);
	//slot = face->glyph;
	
	//const char* text = "rrrr";
	//for (int i = 0; text[i] != '\0'; i++) {
	//	FT_Load_Glyph(face, FT_Get_Char_Index(face, text[i]), FT_LOAD_RENDER);
	//	const FT_Bitmap &bitmap = face->glyph->bitmap;
	//}
	
	Core::WindowOpenGL window;
	Core::ApplicationCore appCore;

	auto input = new InputSystem::InputManagerOpenGL();
	input->SetWindow(window);
	ServiceLocator::Register<InputSystem::IInputManager>(input);
	
	bool success = appCore.Initialize(window);

	if (success) {
		appCore.Update();
	}
	return 0;
}