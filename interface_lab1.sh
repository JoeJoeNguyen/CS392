#!/bin/bash
# interface.sh
# Credit: https://www.computerhope.com/unix/bash/getopts.htm

# TEAM MEMBERS: Son [Joe] Nguyen, Michael Hanna
# LEAD PROGRAMMER: Son Nguyen

#1. Implement a -b option that takes no arguments and uses "Bye" instead of "Hi."
#2. Include a test on the argument of option -t. If the number of times is greater than 20, it should be set to 20.
#3. Include a heredoc in the above test to print out  "You entered X, but the maximum number of times is 20." 
#       X is the argument of option -t entered by the user.

NAME=""                                   # Name of person to greet.
TIMES=1                                   # Number of greetings to give.
usage() {                                 # Function: Print a help message.
  echo "Usage: $0 [ -n NAME ] [ -t TIMES ]" 1>&2   # Redirect stdout to stderr
}
exit_abnormal() {                         # Function: Exit with error.
  usage
  exit 1
}

while getopts ":n:t:b" options; do         # Loop: Get the next option;
                                          # use silent error checking;
                                          # options n and t take arguments.
  case "${options}" in                    #
    b)
      echo Bye!
      exit
      ;;
    n)                                    # If the option is n,
      NAME=${OPTARG}                      # set $NAME to specified value.
      ;;
    t)                                    # If the option is t,
      TIMES=${OPTARG}                     # Set $TIMES to specified value.
      re_isanum='^[0-9]+$'                # Regex: match whole numbers only
      if ! [[ $TIMES =~ $re_isanum ]] ; then   # if $TIMES not whole:
        echo "Error: TIMES must be a positive, whole number."
        exit_abnormal
        exit 1
      elif [ $TIMES -gt "20" ] ; then
        cat <<EOF
You entered $TIMES, but the maximum number of times is 20.
EOF
        TIMES="20"
      elif [ $TIMES -eq "0" ]; then       # If it's zero:
        echo "Error: TIMES must be greater than zero."
        exit_abnormal                     # Exit abnormally.
      fi
      ;;
    :)                                    # If expected argument omitted:
      echo "Error: -${OPTARG} requires an argument."
      exit_abnormal                       # Exit abnormally.
      ;;
    *)                                    # If unknown (any other) option:
      exit_abnormal                       # Exit abnormally.
      ;;
  esac
done

if [ "$NAME" = "" ]; then                 # If $NAME is an empty string,
  STRING="Hi!"                            # our greeting is just "Hi!"
else                                      # Otherwise,
  STRING="Hi, $NAME!"                     # it is "Hi, (name)!"
fi
COUNT=1                                   # A counter.
while [ $COUNT -le $TIMES ]; do           # While counter is less than
                                          # or equal to $TIMES,
  echo $STRING                            # print a greeting,
  let COUNT+=1                            # then increment the counter.
done
exit 0                                    # Exit normally.
