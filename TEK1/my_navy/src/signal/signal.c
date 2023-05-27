/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** signal
*/

#include "local.h"

signals_t signal_g;

void handler(int signum, siginfo_t *info, void *context)
{
    signal_g.sig_num = signum;
    signal_g.sig_pid = info->si_pid;
    signal_g.next = 1;
}

void init_sig_var(struct sigaction *act)
{
    signal_g.next = 0;
    signal_g.sig_num = 0;
    signal_g.sig_pid = 0;
    act->sa_flags = SA_SIGINFO;
    sigemptyset(&act->sa_mask);
    act->sa_sigaction = &handler;
}

int send_int(int nb, int pid)
{
    bool *ar = int_to_bool_arr(nb);
    int success = 0;

    for (int i = 0; i < 32; i++) {
        if (ar[i] == 0)
            success = kill(pid, SIGUSR1);
        else
            success = kill(pid, SIGUSR2);
        if (success == -1)
            return 84;
        usleep(1000);
    }
    return 0;
}

int recev_int(int pid, int timeout)
{
    struct sigaction act;
    bool ar[32] = {0};

    init_sig_var(&act);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    for (int i = 0; i < 32; i++) {
        usleep(timeout * 1000);
        if (signal_g.next == 0)
            return -84;
        signal_g.next = 0;
        if ((signal_g.sig_pid == pid || pid == 0) &&
            (signal_g.sig_num == SIGUSR1 || signal_g.sig_num == SIGUSR2))
            ar[i] = (signal_g.sig_num == SIGUSR2);
        else
            i -= 1;
    }
    return bool_arr_to_int(ar);
}
