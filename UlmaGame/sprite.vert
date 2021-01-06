#version 330
in vec3 inPosition;
in vec3 uv;
uniform mat4 uWorldTransform;
uniform mat4 uViewProj;
out vec2 texCoord;

void main(){
	vec4 pos = vec4(inPosition, 1.0);
	gl_Position = pos * uWorldTransform * uViewProj;
	texCoord = vec2(uv.x, uv.y);
}
