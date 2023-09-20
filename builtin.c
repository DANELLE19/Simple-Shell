#include "shell.h"
/**
 * _myexit - exits the shell
 * @infor: structures containing potential arguments. Used to maintain
 * constat function prototype
 * Return: exits with a given exit status
 * (0) if info.arg[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])/* if there is an exit argument */
	{
		exitcheck = _errato(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "illegal number:");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes current directory
 * @info: struct containing potential arguments for prototype
 * Return: always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO:>>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if
