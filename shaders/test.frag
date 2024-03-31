#version 460 core

in vOutputs {
    vec3 position;
    vec2 texCoord;
} vOut;

out vec4 fragColor;

void main () {
    fragColor = vec4(vOut.texCoord, 0, 1);
}