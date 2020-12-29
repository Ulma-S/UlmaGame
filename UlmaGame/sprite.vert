#version 100

in vec3 inPosition;
in vec3 uv;
//uniform mat4 uWorldTransform;
//uniform mat4 uViewProj;
varying out vec2 texCoord;

void main(){
	vec4 pos = vec4(inPosition, 1.0);
	//gl_Position = pos * uWorldTransform * uViewProj;
	gl_Position = pos;
	texCoord = vec2(uv.x, uv.y);
}