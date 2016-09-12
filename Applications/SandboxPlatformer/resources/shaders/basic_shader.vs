#version 410

in vec3 vp;
uniform mat4 u_modelMatrix;

void
main()
{
	gl_Position = u_modelMatrix * vec4(vp, 1.0);
	//gl_Position = vec4(1.0, 1.0,0.0,0.0);
}

