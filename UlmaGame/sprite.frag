#version 100

varying mediump vec2 texCoord;
uniform sampler2D texture;

void main(){
	gl_FragColor = texture2D(texture, texCoord);
	//gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}