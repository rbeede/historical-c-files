/* VLOAD.C: This program loads a block of virtual
 * memory with _vload, writes to it, and loads in
 * a new block. It then reloads the first block and
 * verifies that its contents haven't changed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <vmemory.h>
void main( void )
{
   int i, flag;
   _vmhnd_t handle1,
            handle2;
   int __far *buffer1;
   int __far *buffer2;
   if ( !_vheapinit( 0, _VM_ALLDOS, _VM_XMS | _VM_EMS ) )
   {
      printf( "Could not initialize virtual memory manager. \n" );
      exit( -1 );
   }
   if ( ( (handle1 = _vmalloc( 100 * sizeof(int) )) == _VM_NULL ) ||
      ( (handle2 = _vmalloc( 100 * sizeof(int) )) == _VM_NULL )   )
   {
      _vheapterm();
      exit( -1 );
   }
   printf( "Two blocks of virtual memory allocated.\n" );
   if ( (buffer1 = (int __far *)_vload( handle1, _VM_DIRTY )) == NULL )
   {
      _vheapterm();
      exit( -1 );
   }
   printf( "buffer1 loaded: valid until next call to VM manager.\n" );
   for ( i = 0; i < 100; i++ )      /* write to buffer1 */
      buffer1[i] = i;
   if ( (buffer2 = (int __far *)_vload( handle2, _VM_DIRTY )) == NULL )
   {
      _vheapterm();
      exit( -1 );
   }
   printf( "buffer2 loaded. buffer 1 no longer valid.\n" );
   if ( (buffer1 = (int __far *)_vload( handle1, _VM_CLEAN )) == NULL )
   {
      _vheapterm();
      exit( -1 );
   }
   printf( "buffer1 reloaded.\n" );
   flag = 0;
   for ( i = 0; i < 100; i++ )
      if ( buffer1[i] != i )
         flag = 1;
   if ( !flag )
      printf( "Contents of buffer1 verified.\n" );
   _vfree( handle1 );
   _vfree( handle2 );
   _vheapterm();
   exit( 0 );
}


