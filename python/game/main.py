import random


class Node:
    number = 0
    ways = []
    chances = []
    isEnd = False


class Player:
    wins = 0
    currentNode = Node()


class GameField:
    field = []

    def create_field(self, size):
        for i in range(size):
            node = Node()
            number = i
            ways = []
            # Begin of field
            if i == 0:
                ways = [1]
            elif i == 1:
                ways = [1, 2]
            elif i < (size - 1):
                ways = [i - 1, i + 1]
            # End of field
            elif i == (size - 1):
                node.isEnd = True
            # Set fields and append in field
            node.number = number
            node.ways = ways
            self.field.append(node)

    def start_game(self):
        # Creating field and players
        self.create_field(6)
        escaping_player = Player()
        hinting_player = Player()
        total_turns = 0
        num_of_games = int(input("Enter number of games: "))
        num_of_turns = int(input("Enter number of turns in game: "))
        is_always_agree = input("Escaping player always agree? - ")
        print()
        if is_always_agree == "y":
            is_always_agree = True
        elif is_always_agree == "n":
            is_always_agree = False
        for game_i in range(num_of_games):
            # Begin of the field
            escaping_player.currentNode = self.field[0]
            # print(f"GAME {game_i + 1}")
            for turn_i in range(num_of_turns):
                total_turns += 1
                # Found exit
                if escaping_player.currentNode.isEnd:
                    break
                way_suggest = random.choice(escaping_player.currentNode.ways)
                # print(f"\nTurn {turn_i + 1}: hinting player suggest way {way_suggest}")
                if is_always_agree or len(escaping_player.currentNode.ways) < 2:
                    # print("Escaping player agreed")
                    escaping_player.currentNode = self.field[way_suggest]
                else:

                    ways = escaping_player.currentNode.ways.copy()
                    ways.remove(way_suggest)
                    way_instead = random.choice(ways)
                    escaping_player.currentNode = self.field[way_instead]
                    # print(f"Escaping player not agreed. He chose way {way_instead}")
            if escaping_player.currentNode.isEnd:
                # print("Escaping player won\n")
                escaping_player.wins += 1
            else:
                # print("Hinting player won\n")
                hinting_player.wins += 1
        print(f"Escaping player wins: {escaping_player.wins}")
        print(f"Hinting player wins: {hinting_player.wins}")
        total_turns = total_turns / num_of_games
        print(f"Average number of turns: {total_turns}")


field = GameField()
game = True
while game:
    field.start_game()
    game = input("Want to continue the game? - ")
    print()
    if game == "y":
        game = True
    elif game == "n":
        game = False
