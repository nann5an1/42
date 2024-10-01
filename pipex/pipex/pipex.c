/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 01:19:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int firstChild(int in_file, int fd[2], char* argv[], char** envp)
{
    int status;
    int pid1 = fork();
    if(pid1 == 0)
    {
        dup2(in_file, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO); //WR_END to STDOUT(1)
        close(fd[0]);
        close(fd[1]);
        close(in_file);
        if(envp_split(argv[2], envp) == 1)//argv[2] = "ls -l"   //"sleep 3"
            exit(1);
        exit(0);
    }
    waitpid(pid1, &status, 0);
    if ( WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}


int secChild(int out_file, int fd[2], char* argv[], char** envp)
{
    int pid2 = fork();
    if(pid2 == 0)
    {
        dup2(out_file, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO); //READ_END to STDOUT(0)
        close(fd[0]);
        close(fd[1]);
        close(out_file);
        if(envp_split(argv[3], envp) == 1)
            exit(1);
        exit (0);
    }
    close(fd[0]);
    close(fd[1]);
    int status;
    waitpid(pid2, &status, 0);
    if ( WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

void sleep_all(char **argv)
{
    char** split;
    int i;
    int max_sleep;

    max_sleep = 0;
    i = 1;
    while(i++ < 4)
    { 
        if(ft_strncmp(argv[i], "sleep", 5) == 0)
        {
            split = ft_split(argv[i], ' ');
            if(ft_atoi(split[1]) > max_sleep)
                max_sleep = ft_atoi(split[1]);
        }
    }
    sleep(max_sleep);     
}
// int main(int argc, char* argv[], char **envp)
// {
//     int fd[2];
//     int in_file;
//     int out_file;
//     char buffer[1024];
    
//     if(argc == 5)
//     {   
//         if(pipe(fd) < 0)
//             errorHandling("Piping failed");
//         if((access(argv[1], F_OK) < 0))
//             errorHandling("File is not accessible");
//         else if(access(argv[1], R_OK) < 0)
//             errorHandling("File is not readable");
//         if(ft_strncmp(argv[1], "/dev/urandom", 11) == 0)
//         {
//             int open_rand = open("/dev/urandom", O_RDONLY);
//             int temp = open("tempfile", O_WRONLY | O_TRUNC | O_CREAT, 0644);
//             int read_rand = read(open_rand, buffer, sizeof(buffer));
//             write(temp, buffer, read_rand);
//             in_file = open("/dev/urandom", O_RDONLY);
//         }
//         else
//             in_file = open(argv[1], O_RDONLY);
//         out_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
//         if(in_file < 0 || out_file < 0)
//             errorHandling("File cannot be opened");
//         if((ft_strncmp(argv[2], "sleep", 5) == 0) && (ft_strncmp(argv[3], "sleep", 5) == 0))
//             sleep_all(argv);
//         else
//         {
//             int res1 = firstChild(in_file, fd, argv, envp);
//             int res2 = secChild(out_file, fd, argv, envp);
//             if(res1 == 1 || res2 == 1)
//                 ft_putstr_fd("Error: Command not found\n" , 2);
//         }
//         close(in_file);
//         close(out_file);
//     }
//     else 
//         ft_putstr_fd("Format Error\n", 2);
// }
int open_files(char *in_file)
{
    int in_fd;
    if(ft_strncmp(in_file, "/dev/urandom", 11) == 0)
            in_fd = open("/dev/urandom", O_RDONLY);
    else 
            in_fd = open(in_file, O_RDONLY);
    return (in_fd);
}
int main(int argc, char* argv[], char **envp)
{
    int ret1;
    int ret2;
    int fd[2];
    int in_file;
    int out_file;
    if (argc != 5)
        return (ft_putstr_fd("Error: Expected Format --> ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2), 1);
    if (pipe(fd) < 0 || access(argv[1], F_OK | R_OK) < 0)
        return (ft_putstr_fd("File is not accessible\n", 2), 1);
    in_file = open_files(argv[1]);
    if (in_file < 0 || (out_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644)) < 0)
        return (ft_putstr_fd("File cannot be opened", 2), 1);
    if (ft_strncmp(argv[2], "sleep", 5) == 0 && ft_strncmp(argv[3], "sleep", 5) == 0)
        sleep_all(argv);
    else
    {
        ret1 = firstChild(in_file, fd, argv, envp);
        ret2 = secChild(out_file, fd, argv, envp);
        if (ret1 == 1 || ret2 == 1)
            ft_putstr_fd("Error: Command not found\n", 2);
    }
    close(in_file);
    close(out_file);
    return (0);
}


    //at the very end add waitpid(pid) to wait for pid to finish