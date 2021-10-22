#include "RoomValidator.h"

bool RoomValidator::checkValid(int num) const
{
    int totalPeople = num;
    int pairRooms = m_baseField[0]->getValidator(5)->getAnswer(5);
    int familyRooms = m_baseField[1]->getValidator(6)->getAnswer(6);

    return (totalPeople <= pairRooms * 2 + familyRooms * 5);
}
