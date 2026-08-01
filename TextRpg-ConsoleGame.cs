using System;
namespace TextRpg
{
    class Character
    {
        public string Name {  get; set; }
        public int Health { get; set; }
        public int Damage { get; set; }
        public Character(string name,int health,int damage) {
            Name = name;
            Health = health;
            Damage = damage;
        }
        public void TakeDamage(int damageAmount)
        {
            Health -= damageAmount;
            if (Health < 0)
                Health = 0;
        }
        public bool IsAlive()
        {
            return Health > 0;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("WELCOME TO TEXTRPG");
            Console.WriteLine("Enter your hero's name: ");
            string playername=Console.ReadLine();

            Character player=new Character(playername,100,20);
            Character monster = new Character("Goblin", 50, 10);
            Console.WriteLine($"\nA wild {monster.Name} appeared!");
            
            while(player.IsAlive() && monster.IsAlive() )
            {
                Console.WriteLine($"[{player.Name} HP: {player.Health}] VS [{monster.Name} HP: {monster.Health}]");
                Console.WriteLine("1 - Attack");
                Console.WriteLine("2 - Run Away");
                Console.WriteLine("Your Choice: ");
                string choice = Console.ReadLine();
                if (choice == "1")
                {
                    Console.WriteLine($"\n{player.Name} dealt {player.Damage} damage to {monster.Name}!");
                    monster.TakeDamage(player.Damage);

                    if (monster.IsAlive())
                    {
                        Console.WriteLine($"{monster.Name} attacked you! You took {monster.Damage} damage.");
                        player.TakeDamage(monster.Damage);
                    }
                }
                else if (choice == "2")
                {
                    Console.WriteLine("\nYou ran away... Battle ended!");
                    break;
                }
                else 
                { 
                    Console.WriteLine("\nInvalid option! Turn wasted."); 
                }
            }
            if(player.IsAlive()&&!monster.IsAlive())
            {
                Console.WriteLine($"VICTORY! {monster.Name} was defeated!");
            }
            else if (!player.IsAlive())
            {
                Console.WriteLine("GAME OVER... You died.");
            }
        }
    }
}