#include "font.h"

// this is an example to show how the class Font used.
// but, it can not run well here.

common::Font kFont;

void RenderFunc(float x, float y, int align, const char* c_str)
{
	// do render c_str
}

int main()
{
	kFont.set_func_render(RenderFunc); // set render font function;
}

void OnGameUpdate(float delta)
{
	int test_val1 = 10;
	kFont.AddInfo("%d", test_val1); // add data at anywhere before render

	// do game update
}

void OnRender()
{
	int test_val2 = 10;
	kFont.AddInfo("%d", test_val2); // add data at anywhere before render

	// do game render

	kFont.RenderInfo(); // at last render info data and then clear it
}