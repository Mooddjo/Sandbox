#version 410

uniform vec4 uColor;
out vec4 color;

void
main()
{
	color = vec4(uColor.r, uColor.g, uColor.b, uColor.a);
//    color = vec4(0.0, 0.5, 1.0, 1.0);
}
