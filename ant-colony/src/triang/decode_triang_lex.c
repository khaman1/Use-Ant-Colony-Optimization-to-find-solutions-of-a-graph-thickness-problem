/* create a triangulation using lex format input */

/*
 * lex format: string of ascii characters with no spaces
 *             each group of three letters represents a face
 * example: abcdba => 2 faces, abca  and dbad, the ending vertix is omitted
 */

#include <stdio.h>
#include <triang.h>
#define DIM 2

int decode_triang_lex(char *text, struct triang *t)
{
  int itext, iface, v[(DIM+1)], nv, nf;

  // determine the number of faces
  nf = strlen(text)/(DIM+1);

  if (nf < 4 || nf > MAX_F) {
    printf("decode_triang_lex: bad format or nf (%d) out of range\n %s\n",
	   nf,text);
    return 0;
  }

  // determine the number of vertices
  nv = 0;
  for (itext=0; itext<(DIM+1)*nf; itext++)
    if (a2i[text[itext]] == -1) {
      printf("decode_triang_lex: bad character (character = %c, hex %X, position %d) in string\n %s\n",
	     text[itext],text[itext],itext,text);
      return 0;
    }
    else if (a2i[text[itext]]+1 > nv)
      nv = a2i[text[itext]]+1;
  
  if (nv < 4 || nv > MAX_V) {
    printf("decode_triang_lex: bad format or nv (%d) out of range\n %s\n",
	   nv,text);
    return 0;
  }
  
  clear_triang(t,nv);
  
  t->nv = nv;
  t->orient = 0;

  itext = 0;
  for (iface=0; iface<nf; iface++) {
    v[0] = a2i[text[itext++]];
    v[1] = a2i[text[itext++]];
    v[2] = a2i[text[itext++]];

    add_face(t,v[0],v[1],v[2]);
  }
  
  t->ne = (3*t->nf)/2;
  t->genus = 2-(t->nv - t->ne + t->nf);
  check_triang(t,"decode_triang_lex");
  return 1;
}
