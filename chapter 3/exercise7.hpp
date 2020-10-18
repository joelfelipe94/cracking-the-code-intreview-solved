#include<list>
#include<string>

enum class Animal_t{dog, cat};
struct Animal
{
    std::string name;
    Animal_t type;
};
class ShelterQueue
{
    using iterator_list = std::list< std::list<Animal>::iterator >;
public:
    void enqueue(const Animal &item);
    Animal dequeueAny();
    Animal dequeueDog();
    Animal dequeueCat();
    
private:
    Animal dequeueSpecific(iterator_list &animalList);
    std::list<Animal> animals;
    iterator_list dogs;
    iterator_list cats;
};

void ShelterQueue::enqueue(const Animal& item)
{
    animals.push_back(item);
    auto it = animals.end();
    --it;
    if(item.type==Animal_t::dog)
        dogs.push_back(it);
    else
        cats.push_back(it);   
}

Animal ShelterQueue::dequeueAny(){
    auto adoptedAnimal = animals.front();
    if(adoptedAnimal.type==Animal_t::dog)
        dogs.pop_front();
    else
        cats.pop_front();
    return adoptedAnimal;
}

Animal ShelterQueue::dequeueDog(){
    return dequeueSpecific(dogs);
}

Animal ShelterQueue::dequeueCat(){
    return dequeueSpecific(cats);
}

Animal ShelterQueue::dequeueSpecific(iterator_list &animalList){
    auto adoptedAnimal = *animalList.front();
    animals.erase(animalList.front());
    animalList.pop_front();
    return adoptedAnimal;
}