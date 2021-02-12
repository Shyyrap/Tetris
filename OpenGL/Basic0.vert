#version 330
uniform mat4 Projection;
uniform mat4 Model;
in vec3 Position;
void main()
{
     gl_Position = Projection*Model*vec4(Position,1.0);
}