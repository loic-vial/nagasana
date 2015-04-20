# version 120

// texture unit used
uniform sampler2D texture0;

// interpolated texture coordinate passed to fragment
varying vec2 frag_texcoord0;

void main()
{
  vec4 texel0 = texture2D( texture0, frag_texcoord0 );
  gl_FragColor = texel0;
}
