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

#include "genes.h"

n_int genes_init(n_genome * genome,
                 n_uint chromosomes,
                 n_uint chromosome_length,
                 n_uint mt_length,
                 n_uint * random_seed)
{
  n_int i,j,k;

  if (chromosomes > LIBGENES_MAX_CHROMOSOMES) return -1;
  if (mt_length > LIBGENES_MAX_CHROMOSOMES) return -2;

  genome->no_of_chromosome_pairs = chromosomes;
  for (i = 0; i < chromosomes; i++) {
    for (j = 0; j < 2; j++) {
      genome->chromosome_pair[i].chromosome[j].length =
        chromosome_length;
      for (k = 0; k < chromosome_length; k++) {
        genome->chromosome_pair[i].chromosome[j].gene[k] =
          (n_gene)genes_rand_num(random_seed);
        genome->chromosome_pair[i].chromosome[j].enable[k] =
          (n_byte)(genes_rand_num(random_seed)&1);
      }
    }
  }
  genome->mt.length = mt_length;
  for (i = 0; i < mt_length; i++) {
    genome->mt.gene[i] =
      (n_gene)genes_rand_num(random_seed);
    genome->mt.enable[i] =
      (n_byte)(genes_rand_num(random_seed)&1);
  }
  return 0;
}

n_int genes_from_parents(n_genome * maternal,
			 n_genome * paternal,
			 n_genome * child)
{
  /* TODO */
  return 0;
}
