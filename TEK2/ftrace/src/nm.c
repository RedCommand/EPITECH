/*
** EPITECH PROJECT, 2023
** Project
** File description:
** nm.c
*/

#include "nm.h"

symbol_t **nm_file(char *filename)
{
    struct stat stat;
    symbol_t **symbol = NULL;
    void *start = NULL;
    int fd = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }
    if (fstat(fd, &stat) == -1)
        return NULL;
    start = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    symbol = nm(start, stat.st_size);
    munmap(start, stat.st_size);
    if (symbol == NULL)
        return NULL;
    return symbol;
}

symbol_t **get_symbols(
    Elf *elf, GElf_Shdr *shdr, Elf_Data *data, GElf_Sym *sym)
{
    symbol_t **symbol = NULL;
    int j = 0;
    int count = 0;

    count = ((shdr->sh_entsize == 0) ? shdr->sh_size
                                     : shdr->sh_size / shdr->sh_entsize);
    symbol = calloc(count + 1, sizeof(symbol_t *));
    for (int i = 0; i < count; i++) {
        if (gelf_getsym(data, i, sym) == NULL)
            continue;
        if (ELF64_ST_TYPE(sym->st_info) != STT_FUNC || sym->st_value == 0)
            continue;
        symbol[j] = malloc(sizeof(symbol_t));
        symbol[j]->name = strdup(elf_strptr(elf, shdr->sh_link, sym->st_name));
        symbol[j]->addr = (void *) (elf_getbase(elf) + sym->st_value);
        j++;
    }
    return symbol;
}

symbol_t **nm(void *start, size_t size)
{
    Elf *elf = NULL;
    Elf_Scn *scn = NULL;
    GElf_Shdr shdr;
    Elf_Data *data = NULL;
    GElf_Sym sym;
    symbol_t **symbols = NULL;

    elf_version(EV_CURRENT);
    elf = elf_memory(start, size);
    while ((scn = elf_nextscn(elf, scn)) != NULL) {
        gelf_getshdr(scn, &shdr);
        if (shdr.sh_type == SHT_SYMTAB)
            break;
    }
    data = elf_getdata(scn, NULL);
    symbols = get_symbols(elf, &shdr, data, &sym);
    elf_end(elf);
    if (symbols == NULL)
        return NULL;
    return symbols;
}

char *get_symbol_name(symbol_t **symbol, void *addr)
{
    if (symbol == NULL || addr == NULL || symbol[0] == NULL)
        return NULL;
    for (int i = 0; symbol[i] != NULL; i++) {
        if (symbol[i]->addr == addr)
            return symbol[i]->name;
    }
    return NULL;
}

void free_symbols(symbol_t **symbols)
{
    if (symbols == NULL)
        return;
    for (int i = 0; symbols[i] != NULL; i++) {
        free(symbols[i]->name);
        free(symbols[i]);
    }
    free(symbols);
}
