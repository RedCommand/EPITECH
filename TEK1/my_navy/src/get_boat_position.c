/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** get_boat_position
*/

#include "local.h"
#include "my.h"

int verify_boat(char *boat)
{
    if (!(is_in_str("23456789", boat[0]) &&
        boat[1] == ':' &&
        is_in_str("ABCDEFGHIJKLMNOPQRSTUVWXYZ", boat[2]) &&
        is_in_str("123456789", boat[3]) &&
        boat[4] == ':' &&
        is_in_str("ABCDEFGHIJKLMNOPQRSTUVWXYZ", boat[5]) &&
        is_in_str("123456789", boat[6])))
        return 0;
    if ((((boat[0] - 48) == (boat[5] - boat[2] + 1)) ^
        ((boat[0] - 48) == ((boat[6] - 48) - (boat[3] - 48) + 1))) &&
        ((boat[2] == boat[5]) ^ (boat[3] == boat[6])))
        return 1;
    if ((((boat[0] - 48) == (boat[2] - boat[5] + 1)) ^
        ((boat[0] - 48) == ((boat[3] - 48) - (boat[6] - 48) + 1))) &&
        ((boat[2] == boat[5]) ^ (boat[3] == boat[6])))
        return 1;
    return 0;
}

int **put_boat_pos(struct boat *boat, int **map)
{
    if (boat->y1 == boat->y2) {
        for (int i = 0; i < boat->size; i++) {
            if (map[boat->x1 + i][boat->y1] == 0)
                map[boat->x1 + i][boat->y1] = boat->size;
            else
                return NULL;
        }
    } else {
        for (int i = 0; i < boat->size; i++) {
            if (map[boat->x1 + i][boat->y1] == 0)
                map[boat->x1][boat->y1 + i] = boat->size;
            else
                return NULL;
        }
    }
    return map;
}

int **extract_boat_position(char *boat_pos, int **map)
{
    struct boat boat;

    boat.size = boat_pos[0] - 48;
    boat.x1 = -65;
    boat.y1 = -49;
    boat.x2 = -65;
    boat.y2 = -49;
    (boat_pos[2] <= boat_pos[5]) ? (boat.x1 += boat_pos[2]) :
    (boat.x2 += boat_pos[5]);
    (boat_pos[2] > boat_pos[5]) ? (boat.x1 += boat_pos[2]) :
    (boat.x2 += boat_pos[5]);
    (boat_pos[3] <= boat_pos[6]) ? (boat.y1 += boat_pos[3]) :
    (boat.y2 += boat_pos[6]);
    (boat_pos[2] > boat_pos[5]) ? (boat.y1 += boat_pos[3]) :
    (boat.y2 += boat_pos[6]);
    return put_boat_pos(&boat, map);
}

int **extract_position(char *file_char)
{
    int **map = init_map();

    for (int i = 0; i < BOAT_NUMBER; i++) {
        if (i > 0)
            file_char = &file_char[8];
        if (verify_boat(file_char) == 0)
            return NULL;
        map = extract_boat_position(file_char, map);
        if (map == NULL)
            return NULL;
    }
    return map;
}

int **get_boat_position(char *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
    char *buff = NULL;
    char *tmpbuff = NULL;
    int **map;

    if (filedesc < 0)
        return NULL;
    buff = malloc(sizeof(char) * (BOAT_NUMBER * 8 + 1));
    if (read(filedesc, buff, (BOAT_NUMBER * 8 - 1)) < 1)
        return NULL;
    buff[(BOAT_NUMBER * 8 - 1)] = '\0';
    tmpbuff = buff;
    map = extract_position(tmpbuff);
    close(filedesc);
    free(buff);
    return map;
}
