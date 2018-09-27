#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include<iostream>

class match
{
public:
    match()=default;
    match(double e, double s):
        escaped(e), score(s) {};
    match(match&)=default;
    ~match()=default;

    match &match_write(double e, double s);

    inline double escaped_read() const{return escaped;}
    inline double score_read() const{return score;}

private:
    double escaped=0;
    double score=0;

};

match match_write(double e, double s)
{
    match to_write(e, s);
    return to_write;
}

class player
{

friend std::ostream &operator<<(std::ostream&, const player&);

public:
    player()=default;
    player(double e, double s):
        total_escaped(e), total_score(s) {};
    player(player&)=default;
    ~player()=default;

    player &add_match(const match&);

    inline double statics_avg_escp() const{return avg_escaped(); }
    inline double stctics_avg_scr() const{return avg_score();}

private:
    inline double avg_escaped() const{return total_escaped/match_count;}
    inline double avg_score() const{return total_score/match_count;}
    double total_escaped=0;
    double total_score=0;
    double match_count=0;
};

std::ostream &operator<<(std::ostream &os, const player &output)
{
    os << output.avg_escaped() <<" " <<output.avg_score() <<std::endl;
    return os;
}

player &player::add_match(const match &new_match)
{
    match_count++;
    total_escaped+=new_match.escaped_read();
    total_score+=new_match.score_read();

    return *this;
}


#endif // MATCH_H_INCLUDED
