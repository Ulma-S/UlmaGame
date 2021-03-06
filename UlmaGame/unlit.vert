#version 100

in mediump vec3 inPosition;
uniform mat4 uWorldTransform;
uniform mat4 uViewProj;

void main(){
	vec4 pos = vec4(inPosition, 1.0);
	gl_Position = pos * uWorldTransform * uViewProj;
}