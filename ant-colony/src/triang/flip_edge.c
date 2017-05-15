/* interchange an edge for the other diagonal of the quadralateral created 
   when the edge is removed */

#include <triang.h>

void flip_edge(struct triang *t, int v1, int v2, int o1, int o2)
{

  /* remove the old faces */

  remove_face(t,v1,v2,o1);
  remove_face(t,v2,v1,o2);

  /* replace them with new ones */

  add_face(t,o1,o2,v2);
  add_face(t,o2,o1,v1);

}
