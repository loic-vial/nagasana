# version 120

// texture coordinate attribute passed from OpenGL
attribute vec2 texcoord0;

// interpolated texture coordinate passed to fragment
varying vec2 frag_texcoord0;

void main(void)
{
  gl_Position = ftransform();
  frag_texcoord0 = texcoord0;
}
