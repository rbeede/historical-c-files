/* VMALLOC.C: This program allocates a block of virtual
 * memory with _vmalloc and uses _vmsize to display the
 * size of that block. Next, it uses _vrealloc to expand
 * the amount of virtual memory and calls _vmsize again
 * to display the new amount of memory allocated.
 */
#include <stdio.h>
#include <stdlib.h>
#include <vmemory.h>

void main( void )
{
    _vmhnd_t handle;
    unsigned long block_size;
	int dummy;

    if ( !_vheapinit( 16000, _VM_ALLDOS, _VM_XMS | _VM_EMS ) )
    {
        printf( "Could not initialize virtual memory manager.\n" );
        exit( -1 );
    }

    printf( "Requesting 100 bytes of virtual memory.\n" );
    if ( (handle = _vmalloc( 100 )) == _VM_NULL )
    {
        _vheapterm();
        exit( -1 );
    }

    block_size = _vmsize( handle );
    printf( "Received %lu bytes of virtual memory.\n", block_size );

    printf( "Resizing block to 200 bytes. \n" );
    if ( (handle = _vrealloc( handle, 200 )) == _VM_NULL )
    {
        _vheapterm();
        exit( -1 );
    }

    block_size = _vmsize( handle );
    printf( "Block resized to %lu bytes.\n", block_size );
dummy = getche();

    _vfree( handle );
    _vheapterm();
}


