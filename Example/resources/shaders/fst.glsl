#version 330

in vec2 TexCoord;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

uniform sampler2D texture1;

out vec4 fragColor;

void main(){
	fragColor = vec4(1.0, 1.0, 1.0, 1.0) * texture(texture1, TexCoord);
}