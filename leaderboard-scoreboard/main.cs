using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
        ????
        While this code was solving the hackkerrank leaderboard problem, existed due to misunderstanding the question.
        ---------------------

        Author : Sir.Geny.00/SyntaxBender

        ----example input----
        6 // num of current leaderboard
        100 90 90 80 75 60 // current leaderboard. it must be decreasing order.
        5 // num of new scores to input to leaderboard
        50 65 77 90 102 // new scores. it must be ascending order.

        ----outputs----
        ranked - it returns latest scoreboard decreasing by scores.
        rankAlignment - return ranking of new scores
     */

    public static List<int> climbingLeaderboard(List<int> ranked, List<int> player)
    {
        int scoreIndex = player.Count-1;
        int rankIndex = 0;
        int rankAlignment = 0;
        List<int> lastStatus = new List<int>();
        while(scoreIndex>-1){
            bool check = false;
            while(rankIndex<ranked.Count){
                if(player[scoreIndex]>=ranked[rankIndex]){
                    check = true;
                    ranked.Insert(rankIndex,player[scoreIndex]);
                    lastStatus.Add(rankAlignment);
                    scoreIndex--;
                }
                if(rankIndex-1<0 || ranked[rankIndex-1] != ranked[rankIndex]) rankAlignment++;
                rankIndex++;
            }
            if(check == false){
                ranked.Add(player[scoreIndex]);
                lastStatus.Add(rankAlignment);
                if(rankIndex-1<0 || ranked[rankIndex-1] != ranked[rankIndex]) rankAlignment++;
                rankIndex++;
                scoreIndex--;
            }
            
        }
        return lastStatus;
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int rankedCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> ranked = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(rankedTemp => Convert.ToInt32(rankedTemp)).ToList();

        int playerCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> player = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(playerTemp => Convert.ToInt32(playerTemp)).ToList();

        List<int> result = Result.climbingLeaderboard(ranked, player);

        textWriter.WriteLine(String.Join("\n", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
 
