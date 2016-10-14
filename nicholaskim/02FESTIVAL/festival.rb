class TestCase
  def initialize(total_number_of_days, number_of_teams, price_per_day)
    @total_number_of_days = total_number_of_days.to_i
    @number_of_teams = number_of_teams.to_i
    @price_per_day = price_per_day.map(&:to_i)
  end

  def compute_possibilities
    minimum_average_price = 101
    price_per_day = @price_per_day.dup
    days = price_per_day.shift(@number_of_teams)
    price = days.inject(0.0) { |sum, e| sum + e } / days.size
    puts price
  end

  def debug
    puts @price_per_day
  end
end

input = $stdin.readlines
number_of_test_cases = input.shift.to_i
output = []

(1..number_of_test_cases).each do |index|
  test_case_input = input.shift(2)
  test_case_properties = test_case_input[0].split(' ')
  test_case_relations = test_case_input[1].split(' ')

  t = TestCase.new(test_case_properties[0],
                   test_case_properties[1],
                   test_case_relations)

  t.compute_possibilities
  t.debug
end
