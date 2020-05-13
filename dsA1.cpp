/*
* FILE			: dsA1.cpp
* PROJECT		: PROG1370 - Assignment 1: Linked Lists
* PROGRAMMER	: Enes Demirsoz
* FIRST VERSION : 2020-02-10
* DESCRIPTION	: The functions in this file are used to get song info from user, and store them in two different sorted doubly linked lists.
*/

#include "dsA1.h"

int main(void)
{
	int check = 0;
	int counter = 0;
	int userInputRating = 0;
	char userInputArtist[kMaxStringLength] = "";
	char userInputTitle[kMaxStringLength] = "";
	struct songInfo* pHeadRatingList = NULL;
	struct songInfo* pTailRatingList = NULL;
	struct songInfo* pHeadArtistList = NULL;
	struct songInfo* pTailArtistList = NULL;
	struct songInfo* pSingleSong = NULL;
	struct songInfo* ptr = NULL;


	for (counter = 0; check != END_INPUT; counter++)
	{
		printf("\nPlease enter Artist Information of song #%d: ", counter + 1);
		fgets(userInputArtist, kMaxStringLength - 1, stdin);
		clearCR(userInputArtist);

		if (strlen(userInputArtist) == 1 && userInputArtist[0] == '.')
		{
			printSongInfo(pHeadRatingList);
			printSongInfo(pHeadArtistList);

			if (pHeadArtistList != NULL && pHeadRatingList != NULL)
			{
				// Ask for additional song to search
				printf("\nPlease enter Artist Information to search the song: ");
				fgets(userInputArtist, kMaxStringLength - 1, stdin);
				clearCR(userInputArtist);
				printf("Please enter Title  Information to search the song: ");
				fgets(userInputTitle, kMaxStringLength - 1, stdin);
				clearCR(userInputTitle);
				printf("Please enter Rating Information to search the song: ");
				userInputRating = getNum();

				if ((pSingleSong = findSong(pHeadArtistList, userInputArtist, userInputTitle)) != NULL && pSingleSong->rating == userInputRating)
				{
					printf("\nPlease Reenter Rating Information to update song information: ");
					userInputRating = getNum();

					if (pSingleSong->rating != userInputRating)
					{
						ptr = pHeadArtistList;

						while (ptr != pSingleSong)
						{
							ptr = ptr->next;
						}
						ptr->rating = userInputRating;

						pSingleSong = findSong(pHeadRatingList, userInputArtist, userInputTitle);
						deleteNode(pSingleSong, &pHeadRatingList, &pTailRatingList);
						pHeadRatingList = ratingSortedLinkedList(pHeadRatingList, &pTailRatingList, userInputArtist, userInputTitle, userInputRating);
					}
				}

				printSongInfo(pHeadRatingList);
				printSongInfo(pHeadArtistList);

			}

			check = END_INPUT;
		}
		else
		{
			printf("Please enter Title  Information of song #%d: ", counter + 1);
			fgets(userInputTitle, kMaxStringLength - 1, stdin);
			clearCR(userInputTitle);

			printf("Please enter Rating Information of song #%d: ", counter + 1);
			userInputRating = getNum();

			pHeadRatingList = ratingSortedLinkedList(pHeadRatingList, &pTailRatingList, userInputArtist, userInputTitle, userInputRating);
			pHeadArtistList = artistSortedLinkedList(pHeadArtistList, &pTailArtistList, userInputArtist, userInputTitle, userInputRating);
		}
	}

	freeAll(pHeadRatingList);
	freeAll(pHeadArtistList);

	pHeadRatingList = NULL;
	pTailRatingList = NULL;
	pHeadArtistList = NULL;
	pTailArtistList = NULL;

	return 0;
}