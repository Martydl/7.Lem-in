/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:06:14 by mde-laga          #+#    #+#             */
/*   Updated: 2019/09/10 15:10:25 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include<stdio.h>

int		main(int ac, char **av)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	int				quit = 0;
	SDL_Rect		rect = {5, 5, 25, 25};

	(void)ac;
	(void)av;
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, 150, 150, 200, 255);
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	SDL_RenderDrawRect(ren, &rect);
	SDL_RenderFillRect(ren, &rect);
	SDL_RenderPresent(ren);
	while (!quit)
	{
		SDL_PollEvent(&event);
		if(event.window.event == SDL_WINDOWEVENT_CLOSE)
			quit = 1;
	}
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
