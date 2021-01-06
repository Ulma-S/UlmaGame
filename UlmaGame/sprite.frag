#version 330
in vec2 texCoord;
uniform sampler2D uTexture;

void main(){
	gl_FragColor = texture2D(uTexture, texCoord);
}