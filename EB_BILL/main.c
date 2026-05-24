#include <stdio.h>

/*
    TNEB / TANGEDCO EB Bill Calculator
    Tariff: Effective July 2024, Updated May 2026
    Source: TNERC Order, tnebbillcalculator.info

    Consumer Types:
    1. Single Phase Home   (LT I-A Domestic)
    2. Three Phase Home    (LT I-A Domestic)
    3. Three Phase Industry (LT III-B, Rs. 7.50/unit)

    IMPORTANT NOTES:
    - Billing is BI-MONTHLY (every 2 months).
    - Two subsidy tiers exist:
        Tier A: <= 500 units bi-monthly -> 200 units FREE (New 2026 scheme)
        Tier B: >  500 units bi-monthly -> 100 units FREE (Telescopic tariff)
    - Telescopic means: crossing 500 units reprices ALL lower slabs.
    - This program uses bi-monthly units. If entering monthly, multiply by 2.
    - Demand charge NOT included.
    - Always verify latest tariff from TANGEDCO / TNERC official site.
*/

/* Consumer type numbers */
#define SINGLE_PHASE_HOME    1
#define THREE_PHASE_HOME     2
#define THREE_PHASE_INDUSTRY 3

/* Extra charge settings - update as needed */
#define ELECTRICITY_TAX_PERCENT 0.0   /* Set if applicable */
#define OTHER_CHARGES           0.0   /* Arrears, penalty, etc. */

/*
    Fixed charges (bi-monthly) based on connected load.
    Up to 500W  -> Rs. 30
    501W - 1kW  -> Rs. 45
    Above 1kW   -> Rs. 45 + Rs. 30 per additional kW
    Enter your load in watts to auto-calculate.
*/
double get_fixed_charge(int load_watts)
{
    if (load_watts <= 500)
        return 30.0;
    else if (load_watts <= 1000)
        return 45.0;
    else
    {
        int extra_kw = (load_watts - 1000 + 999) / 1000; /* ceiling */
        return 45.0 + (extra_kw * 30.0);
    }
}

/*
    Function: calculate_domestic_bill

    TIER A: Bi-monthly consumption <= 500 units
    (New 200 units free scheme - May 2026)
    ------------------------------------------
    1   - 200 units  : Rs. 0.00 (FREE)
    201 - 400 units  : Rs. 4.70 per unit /940
    401 - 500 units  : Rs. 6.30 per unit

    TIER B: Bi-monthly consumption > 500 units
    (Existing telescopic tariff, 100 units free)
    -------------------------------------------
    1   - 100 units  : Rs. 0.00 (FREE)
    101 - 400 units  : Rs. 4.70 per unit
    401 - 500 units  : Rs. 6.30 per unit
    501 - 600 units  : Rs. 8.40 per unit
    601 - 800 units  : Rs. 9.45 per unit
    801 - 1000 units : Rs. 10.50 per unit
    Above 1000 units : Rs. 11.55 per unit

    NOTE: Telescopic means crossing 500 units changes
    the rates applied to ALL lower slabs too.
*/
double calculate_domestic_bill(int units)
{
    double amount = 0.0;

    if (units <= 500)
    {
        /* TIER A: New 200 units free scheme */
        if (units <= 200)
        {
            amount = 0.0;
        }
        else if (units <= 400)
        {
            amount = (units - 200) * 4.70;
        }
        else /* 401 to 500 */
        {
            amount = (200 * 4.70)
                   + (units - 400) * 6.30;
        }
    }
    else
    {
        /* TIER B: Above 500 units - telescopic tariff */
        /* First 100 units free, then full slabs */
        if (units <= 400)
        {
            /* This branch won't be reached (units > 500), kept for clarity */
            amount = (units - 100) * 4.70;
        }
        else if (units <= 500)
        {
            amount = (300 * 4.70)
                   + (units - 400) * 6.30;
        }
        else if (units <= 600)
        {
            amount = (300 * 4.70)
                   + (100 * 6.30)
                   + (units - 500) * 8.40;
        }
        else if (units <= 800)
        {
            amount = (300 * 4.70)
                   + (100 * 6.30)
                   + (100 * 8.40)
                   + (units - 600) * 9.45;
        }
        else if (units <= 1000)
        {
            amount = (300 * 4.70)
                   + (100 * 6.30)
                   + (100 * 8.40)
                   + (200 * 9.45)
                   + (units - 800) * 10.50;
        }
        else
        {
            amount = (300 * 4.70)
                   + (100 * 6.30)
                   + (100 * 8.40)
                   + (200 * 9.45)
                   + (200 * 10.50)
                   + (units - 1000) * 11.55;
        }
    }

    return amount;
}

/*
    Function: calculate_industry_bill
    LT III-B Industry rate: Rs. 7.50 per unit (effective July 2025)
    Demand charge not included.
*/
double calculate_industry_bill(int units)
{
    double industry_rate = 7.50;
    return units * industry_rate;
}

/*
    Function: add_extra_charges
    Adds electricity tax and other charges.
*/
double add_extra_charges(double energy_amount)
{
    double tax_amount = energy_amount * ELECTRICITY_TAX_PERCENT / 100.0;
    return energy_amount + tax_amount + OTHER_CHARGES;
}

int main()
{
    int  consumer_type;
    int  previous_reading;
    int  current_reading;
    int  units;
    int  load_watts;
    char tier;
    double energy_amount;
    double fixed_charge;
    double final_bill;

    printf("=========================================\n");
    printf("  Tamil Nadu (TANGEDCO) EB Bill Calculator\n");
    printf("  Tariff: July 2024 | Updated: May 2026\n");
    printf("=========================================\n");

    printf("\nSelect Consumer Type:\n");
    printf("  1. Single Phase Home  (LT I-A Domestic)\n");
    printf("  2. Three Phase Home   (LT I-A Domestic)\n");
    printf("  3. Three Phase Industry (LT III-B)\n");
    printf("\nEnter consumer type (1/2/3): ");
    scanf("%d", &consumer_type);

    if (consumer_type != SINGLE_PHASE_HOME &&
        consumer_type != THREE_PHASE_HOME  &&
        consumer_type != THREE_PHASE_INDUSTRY)
    {
        printf("\nError: Invalid consumer type.\n");
        return 1;
    }

    printf("Enter previous meter reading (units): ");
    scanf("%d", &previous_reading);

    printf("Enter current meter reading  (units): ");
    scanf("%d", &current_reading);

    units = current_reading - previous_reading;

    if (units < 0)
    {
        printf("\nError: Current reading must be >= previous reading.\n");
        return 1;
    }

    /* Fixed charge input only for domestic */
    fixed_charge = 0.0;
    if (consumer_type == SINGLE_PHASE_HOME || consumer_type == THREE_PHASE_HOME)
    {
        printf("Enter sanctioned load in Watts (e.g. 500, 1000, 2000): ");
        scanf("%d", &load_watts);
        fixed_charge = get_fixed_charge(load_watts);
    }

    printf("\n------------- BILL DETAILS -------------\n");

    if (consumer_type == SINGLE_PHASE_HOME)
    {
        printf("Consumer Type : Single Phase Home\n");
        printf("Tariff Type   : LT I-A Domestic\n");
        energy_amount = calculate_domestic_bill(units);
    }
    else if (consumer_type == THREE_PHASE_HOME)
    {
        printf("Consumer Type : Three Phase Home\n");
        printf("Tariff Type   : LT I-A Domestic\n");
        printf("Note          : 3-phase home uses same domestic slab.\n");
        energy_amount = calculate_domestic_bill(units);
    }
    else
    {
        printf("Consumer Type : Three Phase Industry\n");
        printf("Tariff Type   : LT III-B Industry\n");
        printf("Rate          : Rs. 7.50 per unit\n");
        printf("Note          : Demand charge not included.\n");
        energy_amount = calculate_industry_bill(units);
    }

    /* Show which domestic tier was applied */
    if (consumer_type != THREE_PHASE_INDUSTRY)
    {
        if (units <= 500)
        {
            tier = 'A';
            printf("Subsidy Tier  : A (<=500 units) - First 200 units FREE\n");
        }
        else
        {
            tier = 'B';
            printf("Subsidy Tier  : B (>500 units)  - First 100 units FREE\n");
            printf("                Telescopic tariff applies.\n");
        }
    }

    final_bill = add_extra_charges(energy_amount) + fixed_charge;

    printf("\nPrevious Reading  : %d units\n",   previous_reading);
    printf("Current Reading   : %d units\n",   current_reading);
    printf("Units Consumed    : %d units\n",   units);
    printf("\nEnergy Charges    : Rs. %.2f\n",  energy_amount);
    printf("Fixed Charge      : Rs. %.2f\n",   fixed_charge);
    printf("Electricity Tax   : %.2f %%\n",    ELECTRICITY_TAX_PERCENT);
    printf("Other Charges     : Rs. %.2f\n",   OTHER_CHARGES);
    printf("----------------------------------------\n");
    printf("TOTAL BILL AMOUNT : Rs. %.2f\n",   final_bill);
    printf("----------------------------------------\n");
    printf("\n* This is an estimate. Actual bill may vary.\n");
    printf("* Always verify tariff at tangedco.gov.in\n");

    return 0;
}