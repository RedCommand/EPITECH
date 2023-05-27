/*
** EPITECH PROJECT, 2023
** mynm
** File description:
** nm.h
*/

#pragma once

#include <fcntl.h>
#include <gelf.h>
#include <libelf.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct symbol_s {
    void *addr;
    char *name;
} symbol_t;

symbol_t **nm(void *start, size_t size);
char *get_symbol_name(symbol_t **symbol, void *addr);
symbol_t **get_symbols(
    Elf *elf, GElf_Shdr *shdr, Elf_Data *data, GElf_Sym *sym);
symbol_t **nm_file(char *filename);
void free_symbols(symbol_t **symbols);
