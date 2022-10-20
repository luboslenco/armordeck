//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	WAD I/O functions.
//

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#include "doomtype.h"
#include "m_argv.h"

#include "m_misc.h"
#include "w_file.h"
#include "z_zone.h"

// extern const unsigned int doom1_wad_len;
extern const unsigned char doom1_wad[];

// typedef struct
// {
//     wad_file_t wad;
//     // FILE *fstream;
// } stdc_wad_file_t;

// static stdc_wad_file_t result;


#ifdef _WIN32
// extern wad_file_class_t win32_wad_file;
// unsigned char *file_wad;
#endif


// #ifdef HAVE_MMAP
// extern wad_file_class_t posix_wad_file;
// #endif

// static wad_file_class_t *wad_file_classes[] =
// {
// /*
// #ifdef _WIN32
//     &win32_wad_file,
// #endif
// */
// #ifdef HAVE_MMAP
//     &posix_wad_file,
// #endif
//     &stdc_wad_file,
// };

// extern wad_file_class_t fatfs_wad_file;

// wad_file_t *W_OpenFile(char *path)
// {
    // return NULL;
    //stdc_wad_file_t *result;
    // FILE *fstream;

    // fstream = fopen(path, "rb");

    // if (fstream == NULL)
    // {
        // return NULL;
    // }

    // Create a new stdc_wad_file_t to hold the file handle.

    //result = Z_Malloc(sizeof(stdc_wad_file_t), PU_STATIC, 0);
    // result.wad.file_class = &stdc_wad_file;
    // result.wad.mapped = doom1_wad;
    // result->wad.length = M_FileLength(fstream);
    // result.wad.length = doom1_wad_len;
    // result->fstream = fstream;

    // #ifdef _WIN32
    // FILE *fstream = fopen("C:/Users/lubos/Desktop/DOOM1.iwad", "rb");
    // fseek(fstream, 0, SEEK_END);
    // long lSize = ftell(fstream);
    // result->wad.length = lSize;
    // fseek(fstream, 0, SEEK_SET);
    // file_wad = (unsigned char *)malloc(lSize);
    // fread(file_wad, 1, lSize, fstream);
    // fclose(fstream);
    // #endif

    // return &result.wad;












    // wad_file_t *result;
    // int i;

    // return fatfs_wad_file.OpenFile(path);

    //return stdc_wad_file.OpenFile(path);

    //!
    // Use the OS's virtual memory subsystem to map WAD files
    // directly into memory.
    //

    // if (!M_CheckParm("-mmap"))
    // {
    //     return stdc_wad_file.OpenFile(path);
    // }

    // // Try all classes in order until we find one that works

    // result = NULL;

    // for (i = 0; i < arrlen(wad_file_classes); ++i)
    // {
    //     result = wad_file_classes[i]->OpenFile(path);

    //     if (result != NULL)
    //     {
    //         break;
    //     }
    // }

    // return result;
// }

// void W_CloseFile(wad_file_t *wad)
// {
    // wad->file_class->CloseFile(wad);
// }

// size_t W_Read(wad_file_t *wad, unsigned int offset, void *buffer, size_t buffer_len)
size_t W_Read(unsigned int offset, void *buffer, size_t buffer_len)
{

    // #ifdef _WIN32
    // if (file_wad == NULL) {
    //     FILE *fstream = fopen("C:/Users/lubos/Downloads/DOOM1.WAD", "rb");
    //     fseek(fstream, 0, SEEK_END);
    //     long lSize = ftell(fstream);
    //     fseek(fstream, 0, SEEK_SET);
    //     file_wad = (unsigned char *)malloc(lSize);
    //     fread(file_wad, 1, lSize, fstream);
    //     fclose(fstream);
    // }
    // #endif

    // stdc_wad_file_t *stdc_wad;
    // size_t result;

    // stdc_wad = (stdc_wad_file_t *) wad;

    // // Jump to the specified position in the file.

    // fseek(stdc_wad->fstream, offset, SEEK_SET);

    // // Read into the buffer.

    // result = fread(buffer, 1, buffer_len, stdc_wad->fstream);

    // return result;

    unsigned char *arr = (unsigned char*)buffer;
    for (int i = 0; i < buffer_len; ++i) {
        // #ifdef _WIN32
        // arr[i] = file_wad[offset + i];
        // #else
        arr[i] = doom1_wad[offset + i];
        // #endif
    }
    return buffer_len;




















    // return wad->file_class->Read(wad, offset, buffer, buffer_len);
}

