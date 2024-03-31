#version 460 core

#extension GL_NV_geometry_shader_passthrough : require
#extension GL_NV_viewport_array2 : require

layout (triangles) in;
layout (viewport_relative) out int gl_Layer;

layout (passthrough) in gl_PerVertex {
    vec4 gl_Position;
} gl_in[];

layout (passthrough) in vOutputs {
    vec3 position;
    vec2 texCoord;
} vOut[];

void main() {
    gl_ViewportMask[0] = 7;

    gl_Layer = 0;
}