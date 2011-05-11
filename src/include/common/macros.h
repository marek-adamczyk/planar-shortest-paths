#ifndef _MACROS_H_
#define _MACROS_H_

#define loop(i,n) for( __typeof(n) i = 0; i < (n); i++)
#define mark() printf("[%s| %d]\n", __FILE__, __LINE__);
#define markt(t) printf("[%s| %d]: %s\n", __FILE__, __LINE__, t);

#define all(coll) (coll).begin(), (coll).end()

#endif
