/*
 libgenes - a genetics simulation for artificial life systems
 Copyright (C) 2015  Bob Mottram <bob@robotics.uk.to>

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
 3. Neither the name of the University nor the names of its contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.
 .
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE HOLDERS OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef GENES_H
#define GENES_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "genes_datatypes.h"
#include "genes_random.h"

#define LIBGENES_MAX_CHROMOSOMES 64
#define LIBGENES_MAX_CHROMOSOME_LENGTH 256

typedef n_uint n_gene;

typedef struct {
    n_gene gene[LIBGENES_MAX_CHROMOSOME_LENGTH];
    n_uint length;
} n_chromosome;

typedef struct {
    n_chromosome chromosome[2];
} n_diploid;

typedef struct {
    n_diploid chromosome_pair[LIBGENES_MAX_CHROMOSOMES];
    n_chromosome mt;
    n_uint no_of_chromosome_pairs;
} n_genome;

n_int genes_init(n_genome * genome,
		 n_uint chromosomes,
		 n_uint chromosome_length,
		 n_uint mt_length,
		 n_uint * random_seed);
#endif
