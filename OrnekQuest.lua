quest Elisia begin
    state start begin
        when login begin
            send_letter("Deneme")
        end-- when
        when info or button begin

            --spawn_mob_ext(MOB_KODU,MAP_INDEX,KORDINAT_X,KORDINAT_Y,MOB_SAYISI,AGRASIFMI)
            spawn_mob_ext(101,43,873200,241800,1,false)
            send_letter("Deneme")
        end -- when
    end -- State
end -- quest
