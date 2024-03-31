#version 460 core

uniform mat4 uMVP;

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoord;

out vOutputs {
    vec3 position;
    vec2 texCoord;
} vOut;

void main() {
    vOut.position = aPosition;
    vOut.texCoord = aTexCoord;
    gl_Position = uMVP * vec4(aPosition, 1);
}
